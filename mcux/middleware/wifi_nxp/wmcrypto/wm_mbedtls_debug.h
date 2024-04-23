/** @file wm_mbedtls_debug.h
 *
 *  @brief This file ports debug logs of mbedtls on marvell hardware
 *
 *  Copyright 2008-2020 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef WM_MBEDTLS_DEBUG_H
#define WM_MBEDTLS_DEBUG_H

#include <wmlog.h>

#define wm_mbedtls_e(...) wmlog_e("wm_mbedtls", ##__VA_ARGS__)
#define wm_mbedtls_w(...) wmlog_w("wm_mbedtls", ##__VA_ARGS__)

#ifdef CONFIG_WM_MBEDTLS_DEBUG
#define wm_mbedtls_d(...) wmlog("wm_mbedtls", ##__VA_ARGS__)
#else
#define wm_mbedtls_d(...)
#endif /* !CONFIG_WM_MBEDTLS_DEBUG */

#endif /* WM_MBEDTLS_DEBUG_H */
