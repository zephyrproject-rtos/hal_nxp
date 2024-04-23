/** @file wm_mbedtls_entropy.h
 *
 *  @brief This file contains header for porting mbdedtls entropy functions
 *
 *  Copyright 2008-2020 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef WM_MBEDTLS_ENTROPY_H
#define WM_MBEDTLS_ENTROPY_H

#include <mbedtls/ctr_drbg.h>

int wm_mbedtls_entropy_ctr_drbg_setup();

mbedtls_ctr_drbg_context *wm_mbedtls_get_ctr_drbg_ctx();

#endif /* WM_MBEDTLS_ENTROPY_H */
