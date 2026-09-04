/*
 * Copyright 2023 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#if defined(PSA_CRYPTO_DRIVER_THREAD_EN)
#include "osal_mutex.h"


/**
 * @brief Implementation of mutex_init for thread-safety.
 *
 */
int mcux_mutex_init(mcux_mutex_t *mutex)
{
    //k_mutex_init(mutex);
    return 0;
}

/**
 * @brief Implementation of mutex_free for thread-safety.
 *
 */
int mcux_mutex_free(mcux_mutex_t *mutex)
{
    return 0;
}

/**
 * @brief Implementation of mutex_lock for thread-safety.
 *
 * @return 0 if successful, -1 if not
 */
int mcux_mutex_lock(mcux_mutex_t *mutex)
{
    //k_mutex_lock(mutex, K_FOREVER);
    return 0;
}

/**
 * @brief Implementation of mutex_unlock for thread-safety.
 *
 * @return 0 if successful, -1 if not
 */
int mcux_mutex_unlock(mcux_mutex_t *mutex)
{
    //k_mutex_unlock(mutex);
    return 0;
}
#endif /* PSA_CRYPTO_DRIVER_THREAD_EN */