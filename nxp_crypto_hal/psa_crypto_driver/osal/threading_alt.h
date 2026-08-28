/*
 * Copyright 2024-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*!
 * @file threading_alt.h
 * @brief Declarations for MbedTLS threading_alt functionality.
 *
 * MbedTLS / PSA requires ALT mutex implementations for threading support.
 */

#ifndef __THREADING_ALT_H__
#define __THREADING_ALT_H__

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "tf-psa-crypto/build_info.h"
#else
/* This is for backwards compatibility with MbedTLS 3.x. Post-MbedTLS 3.x this
 * include would only work iff we forced MbedTLS to be built with TF PSA Crypto,
 * which is not a given, since PSA core (TF PSA Crypto) no longer has a hard
 * dependency on MbedTLS >= 4.
 */
#include "mbedtls/build_info.h"
#endif

#include "threading_alt_platform.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Implementation of mbedtls_alt_mutex_init for thread-safety.
 *
 */
void mbedtls_alt_mutex_init(mbedtls_threading_mutex_t *mutex);

/**
 * @brief Implementation of mbedtls_alt_mutex_free for thread-safety.
 *
 */
void mbedtls_alt_mutex_free(mbedtls_threading_mutex_t *mutex);

/*!
 * @brief  Lock the mutex.
 *
 * @return 0 if successful, negative integer otherwise
 */
int mbedtls_alt_mutex_lock(mbedtls_threading_mutex_t *mutex);

/*!
 * @brief  Unlock the mutex.
 *
 * @return 0 if successful, negative integer otherwise
 */
int mbedtls_alt_mutex_unlock(mbedtls_threading_mutex_t *mutex);

extern void mbedtls_threading_set_alt(void (*mutex_init)(mbedtls_threading_mutex_t *),
                                      void (*mutex_free)(mbedtls_threading_mutex_t *),
                                      int (*mutex_lock)(mbedtls_threading_mutex_t *),
                                      int (*mutex_unlock)(mbedtls_threading_mutex_t *));

/*!
 * @brief Provides a function to call mbedtls_threading_set_alt() with
 *        thread_alt based mutex functions required by mbedtls3x and PSA
 *        threading.
 *
 * @return void
 */
void config_mbedtls_threading_alt(void);

#ifdef __cplusplus
}
#endif


#endif /* ifndef __THREADING_ALT_H__ */
