/*
 * Copyright 2024-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*!
 * @file threading_alt.c
 * @brief Alternative threading definitions for MbedTLS with Zephyr.
 *
 * MbedTLS / PSA requires ALT mutex implementations for threading support.
 */

#include "threading_alt.h"
#if defined(MBEDTLS_THREADING_C) && defined(MBEDTLS_THREADING_ALT)
#include "mbedtls/threading.h"

void mbedtls_alt_mutex_init(mbedtls_threading_mutex_t *mutex)
{
    //k_mutex_init(&mutex->mutex);
    mutex->is_valid = 1;
}

void mbedtls_alt_mutex_free(mbedtls_threading_mutex_t *mutex)
{
    if (mutex->is_valid == 1)
    {
        mutex->is_valid = 0;
    }
}

int mbedtls_alt_mutex_lock(mbedtls_threading_mutex_t *mutex)
{
    int ret = MBEDTLS_ERR_THREADING_BAD_INPUT_DATA;

    if (mutex->is_valid == 1)
    {
        //k_mutex_lock(&mutex->mutex, K_FOREVER);
        ret = 0;
    }
    return ret;
}

int mbedtls_alt_mutex_unlock(mbedtls_threading_mutex_t *mutex)
{
    int ret = MBEDTLS_ERR_THREADING_BAD_INPUT_DATA;

    if (mutex->is_valid == 1)
    {
        //k_mutex_unlock(&mutex->mutex);
        ret = 0;
    }
    return ret;
}

void config_mbedtls_threading_alt(void)
{
    /* Configure mbedtls to use threading alt mutexes. */
    mbedtls_threading_set_alt(mbedtls_alt_mutex_init,
                              mbedtls_alt_mutex_free,
                              mbedtls_alt_mutex_lock,
                              mbedtls_alt_mutex_unlock);
}

#endif /* MBEDTLS_THREADING_C && MBEDTLS_THREADING_ALT */
